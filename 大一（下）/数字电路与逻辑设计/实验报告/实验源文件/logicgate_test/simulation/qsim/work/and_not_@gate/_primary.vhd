library verilog;
use verilog.vl_types.all;
entity and_not_Gate is
    port(
        F               : out    vl_logic;
        B               : in     vl_logic;
        A               : in     vl_logic
    );
end and_not_Gate;
