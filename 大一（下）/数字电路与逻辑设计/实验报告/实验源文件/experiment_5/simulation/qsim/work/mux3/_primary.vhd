library verilog;
use verilog.vl_types.all;
entity mux3 is
    port(
        Y               : out    vl_logic;
        d0              : in     vl_logic;
        d1              : in     vl_logic;
        a0              : in     vl_logic;
        d2              : in     vl_logic;
        a1              : in     vl_logic
    );
end mux3;
