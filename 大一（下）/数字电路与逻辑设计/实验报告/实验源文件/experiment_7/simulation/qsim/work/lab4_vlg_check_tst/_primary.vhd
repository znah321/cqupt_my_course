library verilog;
use verilog.vl_types.all;
entity lab4_vlg_check_tst is
    port(
        Q               : in     vl_logic_vector(2 downto 0);
        reset           : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end lab4_vlg_check_tst;
