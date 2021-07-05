library verilog;
use verilog.vl_types.all;
entity mux3_vlg_sample_tst is
    port(
        a0              : in     vl_logic;
        a1              : in     vl_logic;
        d0              : in     vl_logic;
        d1              : in     vl_logic;
        d2              : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end mux3_vlg_sample_tst;
