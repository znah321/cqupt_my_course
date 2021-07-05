library verilog;
use verilog.vl_types.all;
entity MUX151_vlg_check_tst is
    port(
        Code            : in     vl_logic_vector(3 downto 0);
        sampler_rx      : in     vl_logic
    );
end MUX151_vlg_check_tst;
