library verilog;
use verilog.vl_types.all;
entity DigitalClock_vlg_sample_tst is
    port(
        Clock           : in     vl_logic;
        ScanClock       : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end DigitalClock_vlg_sample_tst;
