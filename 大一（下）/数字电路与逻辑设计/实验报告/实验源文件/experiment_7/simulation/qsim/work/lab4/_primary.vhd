library verilog;
use verilog.vl_types.all;
entity lab4 is
    port(
        reset           : out    vl_logic;
        Q               : out    vl_logic_vector(2 downto 0);
        CP              : in     vl_logic
    );
end lab4;
