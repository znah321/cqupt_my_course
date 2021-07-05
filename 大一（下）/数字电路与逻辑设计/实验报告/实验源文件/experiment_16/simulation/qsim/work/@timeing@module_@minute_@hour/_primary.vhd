library verilog;
use verilog.vl_types.all;
entity TimeingModule_Minute_Hour is
    port(
        H               : out    vl_logic_vector(7 downto 0);
        Clock           : in     vl_logic;
        M               : out    vl_logic_vector(7 downto 0)
    );
end TimeingModule_Minute_Hour;
