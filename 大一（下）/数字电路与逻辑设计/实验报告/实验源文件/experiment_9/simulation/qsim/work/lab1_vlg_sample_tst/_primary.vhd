library verilog;
use verilog.vl_types.all;
entity lab1_vlg_sample_tst is
    port(
        CLK             : in     vl_logic;
        CLRN            : in     vl_logic;
        S0              : in     vl_logic;
        S1              : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end lab1_vlg_sample_tst;
