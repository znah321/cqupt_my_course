library verilog;
use verilog.vl_types.all;
entity mux2 is
    port(
        y2m1            : out    vl_logic;
        d1              : in     vl_logic;
        a0              : in     vl_logic;
        d0              : in     vl_logic
    );
end mux2;
