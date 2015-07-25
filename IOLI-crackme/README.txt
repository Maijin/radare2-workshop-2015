======================= IOLI CRACKME v1.2 by pof =======================

[Goal]
	Crack the executable files to accept any password


[Hints]
	Level 0x00: strings is your friend
	Level 0x01: 5274
	Level 0x02: ((10*9)+(123*4))^2
	Level 0x03: same password as in level 0x02
	Level 0x04: 9+6=15 - try 69
	Level 0x05: 9+7=16 but one is not enough - try 970
	Level 0x06: same algorithm as in 5, but envp LOLO=1
	Level 0x07: if you find this level too difficult, try the next
	            one and then come back
	Level 0x08: same algorithm as in 0x06


[Tools]
	strings
		Displays printable strings in files
		included in all linux distributions
		http://sources.redhat.com/binutils/
	
	HT Editor
		File editor/viewer/analyzer for executables.
		sudo apt-get install ht
		http://hte.sourceforge.net/

	radare
		Complete toolchain for working with binary files
		http://radare.nopcode.org/

	IDA Pro
		Interactive multi-processor disassembler and debuger
		http://www.datarescue.com/idabase/

========================================================================
                                 [EOF]
