library verilog;
use verilog.vl_types.all;
entity RS_Latch is
    port(
        Reset           : out    vl_logic;
        Clock           : in     vl_logic;
        R               : in     vl_logic
    );
end RS_Latch;
