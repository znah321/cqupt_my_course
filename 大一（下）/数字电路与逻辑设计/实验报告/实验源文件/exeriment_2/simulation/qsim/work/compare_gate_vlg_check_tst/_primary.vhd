library verilog;
use verilog.vl_types.all;
entity compare_gate_vlg_check_tst is
    port(
        AEB             : in     vl_logic;
        AGE             : in     vl_logic;
        ALB             : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end compare_gate_vlg_check_tst;
