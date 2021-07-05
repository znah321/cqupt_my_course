library verilog;
use verilog.vl_types.all;
entity four_andGate is
    port(
        F               : out    vl_logic;
        A               : in     vl_logic;
        B               : in     vl_logic;
        C               : in     vl_logic;
        D               : in     vl_logic
    );
end four_andGate;
