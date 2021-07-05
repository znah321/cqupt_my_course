library verilog;
use verilog.vl_types.all;
entity lab2 is
    port(
        Q               : out    vl_logic_vector(2 downto 0);
        CP              : in     vl_logic
    );
end lab2;
