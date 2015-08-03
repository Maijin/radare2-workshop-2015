#include <idc.idc>

// define register name and description
// then define access table mask
// [0] - Secure privileged Read
// [1] - Secure privileged Write
// [2] - Nonsecure privileged Read
// [3] - Nonsecure privileged Write
// [4] - Secure User Read
// [5] - Secure User Write
// [6] - Nonsecure User Read
// [7] - Nonsecure User Write

struct {
	char* name;
	char* description;
	char access_mask;
} CP_reg;

#define CP15_MAIN_ID_REGISTER ""
#define CP15_MAIN_ID_REGISTER_ACESS_MASK 0xFF
#define CP15_CACHE_TYPE_REGISTER ""

static char* cp15_reg_comment_parser(char* name, char* description, int access_mask) {
	auto i;
	auto mask_str;
	
	i = name + ": \n" + description + "\n" + mask_str;
	return i;
}

static System_Control_Coprocessor(void) {

// Example: "MRC p15, 0, R0, c0, c0, 1" - Read Cache Type Register

	addr_begin = FirstSeg();
	i = addr_bagin;
	while ( NextAddr(i) != BADADDR ) {
		if (((GetMnem(i) == "MRC") | (GetMnem(i) == "MCR")) & (GetOpnd(i, 0) == 0)) {
			Operand_1 = GetOpnd(i, 1);

			// Extracting "R0" register
			instr_register = substr(Operand_1, 0, 1);
			// Extracting first "c0"
			instr_coprocessor_register1 = substr(Operand_1, 3, 4);
			// Extracting second "c0"
			instr_coprocessor_register2 = substr(Operand_1, 6, 7);
			// Exracting operand parameter
			instr_operand_param = GetOpnd(i, 2);
			switch (instr_coprocessor_register1) {
				case "c0":
					switch (instr_coprocessor_register2) {
						case "c0":
							if (intr_operand_param == 0) {
								// this is an Read Main ID Register
								MakeComm(i, CP_MAIN_ID_REGISTER);
							}
							else {
								// this is a Cache Type Register
								MakeComm(i, CP_CACHE_TYPE_REGISTER);
							}
						case "c1":
						case "c2":
					}
				case "c1":
					switch (instr_coprocessor_register2) {
						case "c0":
						case "c1":
						case "c2":
					}
				case "c2":
				case "c3":
					// Domain Access Control
				case "c5":

				case "c6":
				case "c7":
				case "c8":
				case "c9":
				case "c10":
				case "c11":
				case "c12":
				case "c13":
				case "c14":
				case "c15":
				default:
					Message("Wrong Coprocessor Register!\n");
			}
		}
		i++;
	}
}

static main(void) {
	System_Control_Coprocessor();

}
