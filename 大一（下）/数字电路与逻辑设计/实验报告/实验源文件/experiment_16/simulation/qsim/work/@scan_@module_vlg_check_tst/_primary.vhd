library verilog;
use verilog.vl_types.all;
entity Scan_Module_vlg_check_tst is
    port(
        Code            : in     vl_logic_vector(3 downto 0);
        Dig             : in     vl_logic_vector(7 downto 0);
        sampler_rx      : in     vl_logic
    );
end Scan_Module_vlg_check_tst;
