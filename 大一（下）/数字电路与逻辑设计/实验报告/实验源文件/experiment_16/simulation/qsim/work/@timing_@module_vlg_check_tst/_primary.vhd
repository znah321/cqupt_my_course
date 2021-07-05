library verilog;
use verilog.vl_types.all;
entity Timing_Module_vlg_check_tst is
    port(
        H               : in     vl_logic_vector(7 downto 0);
        M               : in     vl_logic_vector(7 downto 0);
        S               : in     vl_logic_vector(7 downto 0);
        sampler_rx      : in     vl_logic
    );
end Timing_Module_vlg_check_tst;
