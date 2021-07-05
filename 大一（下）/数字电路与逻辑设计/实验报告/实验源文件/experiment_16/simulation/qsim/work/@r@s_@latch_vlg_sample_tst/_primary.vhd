library verilog;
use verilog.vl_types.all;
entity RS_Latch_vlg_sample_tst is
    port(
        Clock           : in     vl_logic;
        R               : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end RS_Latch_vlg_sample_tst;
