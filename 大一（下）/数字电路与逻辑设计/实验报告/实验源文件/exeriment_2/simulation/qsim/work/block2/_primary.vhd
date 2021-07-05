library verilog;
use verilog.vl_types.all;
entity block2 is
    port(
        LB              : out    vl_logic;
        A               : in     vl_logic_vector(1 downto 0);
        B               : in     vl_logic_vector(1 downto 0);
        EB              : out    vl_logic;
        GB              : out    vl_logic
    );
end block2;
