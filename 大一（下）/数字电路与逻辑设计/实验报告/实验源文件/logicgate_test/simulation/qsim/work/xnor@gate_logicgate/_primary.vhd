library verilog;
use verilog.vl_types.all;
entity xnorGate_logicgate is
    port(
        F               : out    vl_logic;
        A               : in     vl_logic;
        B               : in     vl_logic
    );
end xnorGate_logicgate;
