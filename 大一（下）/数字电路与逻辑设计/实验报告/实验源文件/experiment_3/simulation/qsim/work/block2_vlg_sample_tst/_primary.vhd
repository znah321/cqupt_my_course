library verilog;
use verilog.vl_types.all;
entity block2_vlg_sample_tst is
    port(
        L               : in     vl_logic;
        P               : in     vl_logic;
        T               : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end block2_vlg_sample_tst;
