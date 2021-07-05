library verilog;
use verilog.vl_types.all;
entity dMogan_Bool_1 is
    port(
        YLeft           : out    vl_logic;
        A               : in     vl_logic;
        B               : in     vl_logic;
        C               : in     vl_logic;
        YRight          : out    vl_logic
    );
end dMogan_Bool_1;
