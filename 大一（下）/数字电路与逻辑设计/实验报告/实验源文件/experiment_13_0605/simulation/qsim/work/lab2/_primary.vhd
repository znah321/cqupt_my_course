library verilog;
use verilog.vl_types.all;
entity lab2 is
    port(
        Ge              : out    vl_logic_vector(6 downto 0);
        CP              : in     vl_logic;
        Shi             : out    vl_logic_vector(6 downto 0)
    );
end lab2;
