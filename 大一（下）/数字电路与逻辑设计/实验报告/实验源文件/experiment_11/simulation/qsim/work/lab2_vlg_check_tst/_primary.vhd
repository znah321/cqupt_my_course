library verilog;
use verilog.vl_types.all;
entity lab2_vlg_check_tst is
    port(
        F               : in     vl_logic_vector(3 downto 0);
        sBON            : in     vl_logic;
        Y               : in     vl_logic_vector(3 downto 0);
        sampler_rx      : in     vl_logic
    );
end lab2_vlg_check_tst;
