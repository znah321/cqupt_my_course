library verilog;
use verilog.vl_types.all;
entity Second_Count_vlg_check_tst is
    port(
        Carry_Sginal    : in     vl_logic;
        S               : in     vl_logic_vector(7 downto 0);
        sampler_rx      : in     vl_logic
    );
end Second_Count_vlg_check_tst;
