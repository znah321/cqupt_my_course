library verilog;
use verilog.vl_types.all;
entity \Bit-Selective_Signal_Generator\ is
    port(
        Address         : out    vl_logic_vector(2 downto 0);
        CP              : in     vl_logic;
        dig             : out    vl_logic_vector(7 downto 0)
    );
end \Bit-Selective_Signal_Generator\;
