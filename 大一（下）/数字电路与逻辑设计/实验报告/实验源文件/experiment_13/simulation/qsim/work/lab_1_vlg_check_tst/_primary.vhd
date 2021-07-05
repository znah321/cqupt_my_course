library verilog;
use verilog.vl_types.all;
entity lab_1_vlg_check_tst is
    port(
        H               : in     vl_logic_vector(6 downto 0);
        sampler_rx      : in     vl_logic
    );
end lab_1_vlg_check_tst;
