#include <riscv/cpu.hpp>
#include <riscv/instruction/raw_items.hpp>
#include <riscv/instruction/format.hpp>
#include <riscv/register.hpp>
#include <riscv/unit.hpp>
#include <riscv/simulator.hpp>
#include <iostream>

int main()
{
	using namespace riscv;
	simulator::superscalar::quad_core1 simulator;

	instruction::i_raw load;
	instruction::format::base::i& fields = load();
	fields.opcode = 0x3;
	fields.rs = 12;
	fields.rd = 20;
	fields.imm = -2048;

	fields.print_load(std::cout, "lw", &register_::print_gpr_abi_register);
	fields.print_load(std::cout, "lw", &register_::print_fpr_abi_register);

	return 0;
}
