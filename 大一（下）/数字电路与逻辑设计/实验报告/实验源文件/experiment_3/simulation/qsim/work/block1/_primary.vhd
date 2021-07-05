library verilog;
use verilog.vl_types.all;
entity block1 is
    port(
        G               : out    vl_logic;
        L               : in     vl_logic;
        P               : in     vl_logic;
        T               : in     vl_logic;
        Y               : out    vl_logic;
        R               : out    vl_logic
    );
end block1;
