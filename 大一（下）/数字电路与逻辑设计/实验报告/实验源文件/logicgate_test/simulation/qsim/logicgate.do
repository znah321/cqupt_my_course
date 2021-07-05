onerror {exit -code 1}
vlib work
vlog -work work logicgate.vo
vlog -work work four_xorGate_Waveform.vwf.vt
vsim -novopt -c -t 1ps -L cycloneiii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.four_xorGate_vlg_vec_tst -voptargs="+acc"
vcd file -direction logicgate.msim.vcd
vcd add -internal four_xorGate_vlg_vec_tst/*
vcd add -internal four_xorGate_vlg_vec_tst/i1/*
run -all
quit -f
