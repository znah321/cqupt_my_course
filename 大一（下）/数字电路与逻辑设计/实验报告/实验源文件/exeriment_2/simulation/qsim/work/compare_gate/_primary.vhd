library verilog;
use verilog.vl_types.all;
entity compare_gate is
    port(
        AGE             : out    vl_logic;
        B               : in     vl_logic;
        A               : in     vl_logic;
        AEB             : out    vl_logic;
        ALB             : out    vl_logic
    );
end compare_gate;
