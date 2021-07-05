library verilog;
use verilog.vl_types.all;
entity lab1_vlg_sample_tst is
    port(
        clk             : in     vl_logic;
        LDN             : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end lab1_vlg_sample_tst;
