library verilog;
use verilog.vl_types.all;
entity lab1_vlg_check_tst is
    port(
        BON             : in     vl_logic;
        Q               : in     vl_logic_vector(3 downto 0);
        sampler_rx      : in     vl_logic
    );
end lab1_vlg_check_tst;
