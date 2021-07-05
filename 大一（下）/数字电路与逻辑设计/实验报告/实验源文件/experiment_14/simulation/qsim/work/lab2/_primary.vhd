library verilog;
use verilog.vl_types.all;
entity lab2 is
    port(
        seq             : out    vl_logic_vector(6 downto 0);
        A               : in     vl_logic;
        C               : in     vl_logic;
        D               : in     vl_logic;
        B               : in     vl_logic
    );
end lab2;
