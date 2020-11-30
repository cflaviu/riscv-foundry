#ifndef PCH
    #include "riscv/register.hpp"
    #include <iostream>
#endif

namespace riscv
{
	namespace register_
	{
		out_stream& print_gpr_register(out_stream& out, id_t reg_no)
		{
			return out << 'x' << reg_no;
		}

		out_stream& print_gpr_abi_register(out_stream& out, id_t reg_no)
		{
			switch (reg_no)
			{
				case  0: out << "zero"; break;
				case  1: out << "ra"; break;
				case  2: out << "sp"; break;
				case  3: out << "gp"; break;
				case  4: out << "tp"; break;
				case  5:
				case  6:
				case  7: out << 't' << (reg_no - 5); break;
				case  8: out << "s0/fp"; break;
				case  9: out << "s1"; break;
				case 10:
				case 11:
				case 12:
				case 13:
				case 14:
				case 15:
				case 17: out << 'a' << (reg_no - 10); break;
				case 18:
				case 19:
				case 20:
				case 21:
				case 22:
				case 23:
				case 24:
				case 25:
				case 26:
				case 27: out << 's' << (reg_no - 16); break;
				case 28:
				case 29:
				case 30:
				case 31: out << 't' << (reg_no - 25); break;
				default: out << "<ERROR>";
			}

			return out;
		}

		out_stream& print_fpr_register(out_stream& out, id_t reg_no)
		{
			return out << 'f' << reg_no;
		}

		out_stream& print_fpr_abi_register(out_stream& out, id_t reg_no)
		{
			switch (reg_no)
			{
				case  0:
				case  1:
				case  2:
				case  3:
				case  4:
				case  5:
				case  6:
				case  7: out << "ft" << (reg_no - 5); break;
				case  8:
				case  9: out << "fs" << (reg_no - 8); break;
				case 10:
				case 11:
				case 12:
				case 13:
				case 14:
				case 15:
				case 17: out << "fa" << (reg_no - 10); break;
				case 18:
				case 19:
				case 20:
				case 21:
				case 22:
				case 23:
				case 24:
				case 25:
				case 26:
				case 27: out << "fs" << (reg_no - 16); break;
				case 28:
				case 29:
				case 30:
				case 31: out << "ft" << (reg_no - 20); break;
				default: out << "<ERROR>";
			}

			return out;
		}
	}
}
