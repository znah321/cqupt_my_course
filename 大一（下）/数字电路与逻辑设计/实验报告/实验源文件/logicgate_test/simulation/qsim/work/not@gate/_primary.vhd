library verilog;
use verilog.vl_types.all;
entity notGate is
    port(
        F               : out    vl_logic;
        A               : in     vl_logic
    );
end notGate;
