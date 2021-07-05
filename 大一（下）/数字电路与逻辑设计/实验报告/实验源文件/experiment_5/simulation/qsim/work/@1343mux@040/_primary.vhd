library verilog;
use verilog.vl_types.all;
entity \3mux\ is
    port(
        Y               : out    vl_logic;
        d0              : in     vl_logic;
        d1              : in     vl_logic;
        a0              : in     vl_logic;
        d2              : in     vl_logic;
        a1              : in     vl_logic
    );
end \3mux\;
