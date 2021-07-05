library verilog;
use verilog.vl_types.all;
entity DigitalClock is
    port(
        Dig             : out    vl_logic_vector(7 downto 0);
        ScanClock       : in     vl_logic;
        Seg             : out    vl_logic_vector(6 downto 0);
        Clock           : in     vl_logic
    );
end DigitalClock;
