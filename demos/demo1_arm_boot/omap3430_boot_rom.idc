#include <idc.idc>
// Relocate one segment
static SegCopy(src, dest, size)
{
	 auto ea_src, ea_dest, hi_limit;
     hi_limit = src + size;
	 ea_dest = dest;
	 for(ea_src = src; ea_src < hi_limit ; ea_src = ea_src + 4 )
	 {
		PatchDword( ea_dest, Dword(ea_src));
		ea_dest = ea_dest + 4;
	 }
	 Message("segment copy finished(inside SegCopy function)...\n");
}

static main()
{
	Message("creating target segment(inside entry point function main)...\n");
	AddSeg(0x00014000, 0x0001C000, 0x00000000, 0, 0, 0);
	RenameSeg(0x00014000, "ROM_ORIG"); // Give a new name to the segment.
	SegCopy(0x40014000, 0x00014000, 0x8000);
} 
