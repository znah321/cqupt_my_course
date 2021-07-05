library verilog;
use verilog.vl_types.all;
entity block1_vlg_sample_tst is
    port(
        a               : in     vl_logic;
        clk             : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end block1_vlg_sample_tst;
