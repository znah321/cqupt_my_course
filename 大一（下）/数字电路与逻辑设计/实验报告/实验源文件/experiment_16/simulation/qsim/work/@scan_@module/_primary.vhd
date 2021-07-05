library verilog;
use verilog.vl_types.all;
entity Scan_Module is
    port(
        Code            : out    vl_logic_vector(3 downto 0);
        ScanClock       : in     vl_logic;
        Clock           : in     vl_logic;
        Dig             : out    vl_logic_vector(7 downto 0)
    );
end Scan_Module;
