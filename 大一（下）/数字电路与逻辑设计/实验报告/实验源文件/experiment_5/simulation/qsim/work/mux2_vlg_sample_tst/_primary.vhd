library verilog;
use verilog.vl_types.all;
entity mux2_vlg_sample_tst is
    port(
        a0              : in     vl_logic;
        d0              : in     vl_logic;
        d1              : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end mux2_vlg_sample_tst;
