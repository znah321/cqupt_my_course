library verilog;
use verilog.vl_types.all;
entity DigitalClock_vlg_check_tst is
    port(
        Dig             : in     vl_logic_vector(7 downto 0);
        Seg             : in     vl_logic_vector(6 downto 0);
        sampler_rx      : in     vl_logic
    );
end DigitalClock_vlg_check_tst;
