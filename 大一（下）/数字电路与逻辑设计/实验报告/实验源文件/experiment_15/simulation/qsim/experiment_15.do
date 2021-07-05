onerror {exit -code 1}
vlib work
vlog -work work experiment_15.vo
vlog -work work Waveform_Second_Count.vwf.vt
vsim -novopt -c -t 1ps -L cycloneiii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.Count_S_vlg_vec_tst -voptargs="+acc"
vcd file -direction experiment_15.msim.vcd
vcd add -internal Count_S_vlg_vec_tst/*
vcd add -internal Count_S_vlg_vec_tst/i1/*
run -all
quit -f
