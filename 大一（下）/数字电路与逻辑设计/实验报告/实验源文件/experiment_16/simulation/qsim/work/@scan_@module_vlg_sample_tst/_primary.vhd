library verilog;
use verilog.vl_types.all;
entity Scan_Module_vlg_sample_tst is
    port(
        Clock           : in     vl_logic;
        ScanClock       : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end Scan_Module_vlg_sample_tst;
