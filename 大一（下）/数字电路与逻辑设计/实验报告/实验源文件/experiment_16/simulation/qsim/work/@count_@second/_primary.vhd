library verilog;
use verilog.vl_types.all;
entity Count_Second is
    port(
        Carry_Signal    : out    vl_logic;
        S               : out    vl_logic_vector(7 downto 0);
        Clock           : in     vl_logic
    );
end Count_Second;
