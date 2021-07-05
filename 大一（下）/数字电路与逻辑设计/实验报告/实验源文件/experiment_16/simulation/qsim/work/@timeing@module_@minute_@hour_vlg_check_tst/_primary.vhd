library verilog;
use verilog.vl_types.all;
entity TimeingModule_Minute_Hour_vlg_check_tst is
    port(
        H               : in     vl_logic_vector(7 downto 0);
        M               : in     vl_logic_vector(7 downto 0);
        sampler_rx      : in     vl_logic
    );
end TimeingModule_Minute_Hour_vlg_check_tst;
