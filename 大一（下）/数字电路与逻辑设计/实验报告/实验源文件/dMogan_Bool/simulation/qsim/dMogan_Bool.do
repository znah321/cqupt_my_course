onerror {exit -code 1}
vlib work
vlog -work work dMogan_Bool.vo
vlog -work work dMogan_Bool_2_Waveform.vwf.vt
vsim -novopt -c -t 1ps -L cycloneiii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.dMogan_Bool_2_vlg_vec_tst -voptargs="+acc"
vcd file -direction dMogan_Bool.msim.vcd
vcd add -internal dMogan_Bool_2_vlg_vec_tst/*
vcd add -internal dMogan_Bool_2_vlg_vec_tst/i1/*
run -all
quit -f
