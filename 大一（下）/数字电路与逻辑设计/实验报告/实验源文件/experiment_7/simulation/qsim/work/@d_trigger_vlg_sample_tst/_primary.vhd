library verilog;
use verilog.vl_types.all;
entity D_trigger_vlg_sample_tst is
    port(
        CLRN            : in     vl_logic;
        CP              : in     vl_logic;
        D               : in     vl_logic;
        PRN             : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end D_trigger_vlg_sample_tst;
