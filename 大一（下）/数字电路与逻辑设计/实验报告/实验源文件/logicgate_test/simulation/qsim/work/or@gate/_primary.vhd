library verilog;
use verilog.vl_types.all;
entity orGate is
    port(
        F               : out    vl_logic;
        B               : in     vl_logic;
        A               : in     vl_logic
    );
end orGate;
