library verilog;
use verilog.vl_types.all;
entity lab1 is
    port(
        seq             : out    vl_logic_vector(6 downto 0);
        CP              : in     vl_logic
    );
end lab1;
