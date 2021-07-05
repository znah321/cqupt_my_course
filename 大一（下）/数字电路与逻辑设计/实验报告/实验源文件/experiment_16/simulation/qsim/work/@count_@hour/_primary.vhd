library verilog;
use verilog.vl_types.all;
entity Count_Hour is
    port(
        H               : out    vl_logic_vector(7 downto 0);
        Clock           : in     vl_logic
    );
end Count_Hour;
