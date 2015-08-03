import idaapi
import idautils
import idc

import math
from M2Crypto import BIO, RSA, EVP
from pyasn1.codec.der import decoder

# Key generation:
# openssl genrsa -out rsatest.key 1024
# openssl rsa -in rsatest.key -pubout -out rsatest.pub
# openssl rsa -modulus -in rsatest.key

def big_endian(n):
	s = '%x' % n
	if len(s) & 1:
		s = '0' + s
	return s.decode('hex')

def construct_public_key(public_exponent, modulus, key_size):
	
	# N_PREFIX depends on key length
	#key_size = math.trunc(math.log(modulus, 2)) + 1

	if key_size == 256 :
		N_PREFIX = '\x00\x00\x00\x00'
	elif key_size == 512 :
		N_PREFIX = '\x00\x00\x00A\x00'
	elif key_size == 1024 :
		N_PREFIX = '\x00\x00\x00\x81\x00'
	elif (key_size == 2048) | (key_size == 2047) :
		N_PREFIX = '\x00\x00\x01\x01\x00'
	elif key_size == 4096 :
		N_PREFIX = '\x00\x00\x02\x01\x00'
	else :
		N_PREFIX = '\x00\x00\x00\x00'
	
	# E_PREFIX depends on E value

	if public_exponent == 65537 :
		E_PREFIX = '\x00\x00\x00\x03'
	elif public_exponent == 3 :
		E_PREFIX = '\x00\x00\x00\x01'
	else :
		E_PREFIX = '\x00\x00\x00\x00'

	e =  E_PREFIX + big_endian(public_exponent)
	n =  N_PREFIX + big_endian(modulus)
	key = RSA.new_pub_key((e,n))
	return key

# 1. Found all certificates and digests in file
# 2. Try recognize them with the structure and ASN1 parser
# 3. List them and provide address
# 4. Mark them as structures
# 5. Make PEM and DER formats of all of them

def parse_structures():
	
	# Searching structures, and if not exists - creating them

	# RSA KEY structure

	rsa_key = idc.GetStrucIdByName("rsa_key")
	rsa_key_str = """ struct rsa_key {
								long key_id;
								long key_type;
								long key_rights;
								long modul_length;
								long e_value;
								char modul[256];
							  }; """
	if rsa_key == -1:
		rsa_key = idc.AddStrucEx(-1, "rsa_key", 0)
		idc.AddStrucMember(rsa_key, "key_id", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(rsa_key, "key_type", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(rsa_key, "key_rights", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(rsa_key, "modul_length", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(rsa_key, "e_value", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(rsa_key, "modul", -1, (FF_BYTE|FF_DATA)&0xFFFFFFFF, -1, 256)
	
	# RSA ASN1 DIGEST structure

	rsa_asn1_digest = idc.GetStrucIdByName("rsa_asn1_digest")
	rsa_asn1_digest_str = """ struct rsa_asn1_digest {
									char signer_info[16];
									long signature_info;
									long key_id;
									char digest[256];
							  }; """
	if rsa_asn1_digest == -1:
		rsa_asn1_digest = idc.AddStrucEx(-1, "rsa_asn1_digest", 0)
		idc.AddStrucMember(rsa_asn1_digest, "signer_info", -1, (FF_BYTE|FF_DATA)&0xFFFFFFFF, -1, 16)
		idc.AddStrucMember(rsa_asn1_digest, "signature_info", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(rsa_asn1_digest, "key_id", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(rsa_asn1_digest, "digest", -1, (FF_BYTE|FF_DATA)&0xFFFFFFFF, -1, 256)
	
	# Cert PK - Public Keys structure

	certpk_struct = idc.GetStrucIdByName("Cert_Public")
	certpk_str = """ struct certpk {
						char cert_mark[8];
						long cert_version;
						long cert_type;
						long minver_pk;
						long minver_ppa;
						long minver_rd1;
						long minver_rd2;
						long minver_isw;
						long minver_ki;
						long minver_pau;
						long minver_pas;
						long unkn1;
						struct {
							long key_id;
							long key_type;
							long key_rights;
							long modul_length;
							long e_value;
							char modul[256];
						} root_key;
						long keys_active;
						struct {
							long key_id;
							long key_type;
							long key_rights;
							long modul_length;
							long e_value;
							char modul[256];
						} key_02;
						struct {
							long key_id;
							long key_type;
							long key_rights;
							long modul_length;
							long e_value;
							char modul[256];
						} key_03;
						struct {
							long key_id;
							long key_type;
							long key_rights;
							long modul_length;
							long e_value;
							char modul[256];
						} key_04;
						struct {
							long key_id;
							long key_type;
							long key_rights;
							long modul_length;
							long e_value;
							char modul[256];
						} key_05;
						struct {
							long key_id;
							long key_type;
							long key_rights;
							long modul_length;
							long e_value;
							char modul[256];
						} key_06;
						struct {
							long key_id;
							long key_type;
							long key_rights;
							long modul_length;
							long e_value;
							char modul[256];
						} key_07;
						long rights;
						long msv_mask;
						char zero_hole_2[120];
						struct {
							char signer_info[16];
							long signature_info;
							long key_id;
							char digest[256];
						} digest;
					};"""
	if certpk_struct == -1:
		certpk_struct = idc.AddStrucEx(-1, "Cert_Public", 0)
		idc.AddStrucMember(certpk_struct, "cert_mark", -1, (FF_BYTE|FF_DATA)&0xFFFFFFFF, -1, 8)
		idc.AddStrucMember(certpk_struct, "cert_version", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certpk_struct, "cert_type", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certpk_struct, "minver_pk", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certpk_struct, "minver_ppa", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certpk_struct, "minver_rd1", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certpk_struct, "minver_rd2", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certpk_struct, "minver_isw", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certpk_struct, "minver_ki", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certpk_struct, "minver_pau", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certpk_struct, "minver_pas", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certpk_struct, "unkn1", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certpk_struct, "root_key", -1, 0x60000400, rsa_key, idc.GetStrucSize(rsa_key))
		idc.AddStrucMember(certpk_struct, "keys_active", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certpk_struct, "key_02", -1, 0x60000400, rsa_key, idc.GetStrucSize(rsa_key))
		idc.AddStrucMember(certpk_struct, "key_03", -1, 0x60000400, rsa_key, idc.GetStrucSize(rsa_key))
		idc.AddStrucMember(certpk_struct, "key_04", -1, 0x60000400, rsa_key, idc.GetStrucSize(rsa_key))
		idc.AddStrucMember(certpk_struct, "key_05", -1, 0x60000400, rsa_key, idc.GetStrucSize(rsa_key))
		idc.AddStrucMember(certpk_struct, "key_06", -1, 0x60000400, rsa_key, idc.GetStrucSize(rsa_key))
		idc.AddStrucMember(certpk_struct, "key_07", -1, 0x60000400, rsa_key, idc.GetStrucSize(rsa_key))
		idc.AddStrucMember(certpk_struct, "rights", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certpk_struct, "msv_mask", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certpk_struct, "zero_hole_2", -1, (FF_BYTE|FF_DATA)&0xFFFFFFFF, -1, 120)
		idc.AddStrucMember(certpk_struct, "digest", -1, 0x60000400, rsa_asn1_digest, idc.GetStrucSize(rsa_asn1_digest))
	
	# CertPPA - Primary Protected Application Certificate structure

	certppa_struct = idc.GetStrucIdByName("Cert_Primary")
	certppa_str = """ struct certppa {
							char cert_mark[8];
							long cert_version;
							long cert_type;
							long minver_src;
							long minver_pk;
							long minver_ppa;
							long minver_rd1;
							long minver_rd2;
							long minver_isw;
							struct {
								int image_offset;
								int image_size;
								int data_byte[5];
							} images[4];
							char zero_hole[128];
							struct {
								char signer_info[16];
								long signature_info;
								long key_id;
								char digest[256];
							} digest;
						};"""
	if certppa_struct == -1:
		certppa_struct = idc.AddStrucEx(-1, "Cert_Primary", 0)
		idc.AddStrucMember(certppa_struct, "cert_mark", -1, (FF_BYTE|FF_DATA)&0xFFFFFFFF, -1, 8)
		idc.AddStrucMember(certppa_struct, "cert_version", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certppa_struct, "cert_type", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certppa_struct, "minver_src", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certppa_struct, "minver_pk", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certppa_struct, "minver_ppa", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certppa_struct, "minver_rd1", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certppa_struct, "minver_rd2", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certppa_struct, "minver_isw", -1, (FF_DWRD|FF_DATA)&0xFFFFFFFF, -1, 4)
		idc.AddStrucMember(certppa_struct, "images", -1, (FF_BYTE|FF_DATA)&0xFFFFFFFF, -1, 21)
		idc.AddStrucMember(certppa_struct, "zero_hole", -1, (FF_BYTE|FF_DATA)&0xFFFFFFFF, -1, 128)
		idc.AddStrucMember(certppa_struct, "digest", -1, 0x60000400, rsa_asn1_digest, idc.GetStrucSize(rsa_asn1_digest))

	# CertISW - Initial Software Certificate structure

	certisw_struct = idc.GetStrucIdByName("Cert_ISW")
	certisw_str = """struct certisw {
							char cert_mark[8];
							int cert_version;
							int cert_type;
							int minver_src;
							int minver_pk;
							int minver_ppa;
							int minver_rd1;
							int minver_rd2;
							int minver_isw;
							int watchdog_param;
							int use_DMA;
							int active_images;
							struct {
								int image_offset;
								int image_size;
								int data_byte[5];
							} images[4];
							int magic_1;
							int reg_bitfield;
							struct {
								int reg_address;
								int reg_value;
							} reg_table[32];
							int reg_type_01;
							int reg_type_02;
							int entry_point_offset;
							int zero_hole[32];
							struct {
								char signer_info[16];
								long signature_info;
								long key_id;
								char digest[256];
							} digest;
					};"""

	mbmloader_hdr_str = """struct mbmloader_head {
								void *entry_point;
								int anonymous_0;
								void *anonymous_1;
								void *anonymous_2;
								void *anonymous_3;
								void *anonymous_4;
								int anonymous_5;
								int field_1C;
								void *anonymous_7;
								int field_24;
								void *anonymous_8;
								int anonymous_9;
								int ruler[4];
								char srk_part_1[128];
								int srk_1;
								void *srk_1_pointer;
								int field_C8;
								int field_CC;
								char srk_part_2[128];
								int srk_2;
								void *srk_2_pointer;
								int field_158;
								int field_15C;
								char sha_160_hash[20];
						};"""

	# Searching main structures marks

	start = idc.MinEA()
	stop = idc.MaxEA()
	certpk_addr = idaapi.find_binary(start, stop, "43 65 72 74 50 4B 5F 00", 0, 0) # "CertPK_" string
	print "Found CertPK at 0x%x" % certpk_addr
	certppa_addr = idaapi.find_binary(start, stop, "43 65 72 74 50 50 41 00", 0, 0) # "CertPPA" string
	print "Found CertPPA at 0x%x" % certppa_addr
	certisw_addr = idaapi.find_binary(start, stop, "43 65 72 74 49 53 57 00", 0, 0) # "CertISW" string
	print "Found CertISW at 0x%x" % certisw_addr

	# Apply structure types on Cert* addresses

	# Read Structures from such data

	# If type is not parsed already, then...
	if idc.ParseTypes("certpk;", idc.PT_SILENT) != 0:
		# ...define the type
		idc.ParseTypes(certpk_str, idc.PT_SILENT)
	
	if idc.ParseTypes("certppa;", idc.PT_SILENT) != 0:
		idc.ParseTypes(certppa_str, idc.PT_SILENT)

	if idc.ParseTypes("certisw;", idc.PT_SILENT) != 0:
		idc.ParseTypes(certisw_str, idc.PT_SILENT)

	certpk_ = idaapi.Appcall.typedobj("certpk;")
	certpk_read, certpk = certpk_.retrieve(idaapi.get_many_bytes(certpk_addr, certpk_.size))

	certppa_ = idaapi.Appcall.typedobj("certppa;")
	certppa_read, certppa = certppa_.retrieve(idaapi.get_many_bytes(certppa_addr, certppa_.size))

	certisw_ = idaapi.Appcall.typedobj("certisw;")
	certisw_read, certisw = certisw_.retrieve(idaapi.get_many_bytes(certisw_addr, certisw_.size))

	# Make PEM keys
	if certpk_read == 1 :
		root_key = construct_public_key(certpk.root_key.e_value, int(certpk.root_key.modul[0:certpk.root_key.modul_length].encode("hex"), 16), certpk.root_key.modul_length * 8)
		root_key.save_key("root_key.pem")

		# TODO: add automatic export of all ACTIVE keys from certpk.active_keys
		pk_02 = construct_public_key(certpk.key_02.e_value, int(certpk.key_02.modul[0:certpk.key_02.modul_length].encode("hex"), 16), certpk.key_02.modul_length * 8)
		pk_02.save_key("pk_02.pem")
		pk_03 = construct_public_key(certpk.key_03.e_value, int(certpk.key_03.modul[0:certpk.key_03.modul_length].encode("hex"), 16), certpk.key_03.modul_length * 8)
		pk_03.save_key("pk_03.pem")
		pk_04 = construct_public_key(certpk.key_04.e_value, int(certpk.key_04.modul[0:certpk.key_04.modul_length].encode("hex"), 16), certpk.key_04.modul_length * 8)
		pk_04.save_key("pk_04.pem")
	else :
		print "CertPK read fail!"
	
	# Verify digests
	if (certpk_read == 1) & (certppa_read == 1) & (certisw_read == 1) :
		certpk_digest =  certpk.digest.digest.encode("hex")
		certppa_digest = certppa.digest.digest.encode("hex")
		certisw_digest = certisw.digest.digest.encode("hex")
		# pk_03.public_decrypt(certisw_digest, 1)
		# pk_03.verify(idaapi.get_many_bytes(certisw_addr, certisw_.size), certisw_digest, "sha1")
		# decoder.decode(certpk.digest.signer_info, )
		print "CertPK signer info: %s " % certpk.digest.signer_info.encode("hex")
		print "CertPK digest: %s " % certpk.digest.digest.encode("hex")
		print "CertPPA signer info: %s " % certppa.digest.signer_info.encode("hex")
		print "CertPPA digest: %s " % certppa.digest.digest.encode("hex")
		print "CertISW signer info: %s " % certisw.digest.signer_info.encode("hex")
		print "CertISW digest: %s " % certisw.digest.digest.encode("hex")
	else :
		print "Certs processing fail!"

	# TODO: Parse rights of the keys
	# TODO: Parse ASN1 from digests

	# Processing Images
	i = 0
	while i < 4 :
		print "images type %s " % type (certppa.images)
		if certppa.images[i].image_offset != 0 :
			print "Found PPA image at %x offset " % certppa.images[i].image_offset
		if certisw.images[i].image_offset != 0 :
			print "Found ISW image at %x offset " % certisw.images[i].image_offset
		i += 1

	# image start at certppa mark address + certppa.images[i].image_offset


# Script body

start = idc.MinEA()
stop = idc.MaxEA()
version_addr = idaapi.find_binary(start, stop, "43 65 72 74 49 53 57 00", 0, 0) + 0x79e # "CertISW" string
version_minor = idaapi.get_byte(version_addr)
version_major = idaapi.get_byte(version_addr + 1)
print "MBM loader Major Version: %x " % version_major
print "MBM loader Minor Version: %x " % version_minor
parse_structures()

