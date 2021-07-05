-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 13.1.0 Build 162 10/23/2013 SJ Full Version"

-- DATE "04/29/2020 18:51:13"

-- 
-- Device: Altera EP3C16Q240C8 Package PQFP240
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIII;
LIBRARY IEEE;
USE CYCLONEIII.CYCLONEIII_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	compare_gate IS
    PORT (
	AGE : OUT std_logic;
	B : IN std_logic;
	A : IN std_logic;
	AEB : OUT std_logic;
	ALB : OUT std_logic
	);
END compare_gate;

-- Design Ports Information
-- AGE	=>  Location: PIN_63,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- AEB	=>  Location: PIN_13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ALB	=>  Location: PIN_20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A	=>  Location: PIN_22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B	=>  Location: PIN_41,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF compare_gate IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_AGE : std_logic;
SIGNAL ww_B : std_logic;
SIGNAL ww_A : std_logic;
SIGNAL ww_AEB : std_logic;
SIGNAL ww_ALB : std_logic;
SIGNAL \AGE~output_o\ : std_logic;
SIGNAL \AEB~output_o\ : std_logic;
SIGNAL \ALB~output_o\ : std_logic;
SIGNAL \B~input_o\ : std_logic;
SIGNAL \A~input_o\ : std_logic;
SIGNAL \inst~0_combout\ : std_logic;
SIGNAL \inst5~combout\ : std_logic;
SIGNAL \inst3~0_combout\ : std_logic;
SIGNAL \ALT_INV_inst5~combout\ : std_logic;

BEGIN

AGE <= ww_AGE;
ww_B <= B;
ww_A <= A;
AEB <= ww_AEB;
ALB <= ww_ALB;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_inst5~combout\ <= NOT \inst5~combout\;

-- Location: IOOBUF_X3_Y0_N9
\AGE~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst~0_combout\,
	devoe => ww_devoe,
	o => \AGE~output_o\);

-- Location: IOOBUF_X0_Y25_N16
\AEB~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_inst5~combout\,
	devoe => ww_devoe,
	o => \AEB~output_o\);

-- Location: IOOBUF_X0_Y22_N23
\ALB~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst3~0_combout\,
	devoe => ww_devoe,
	o => \ALB~output_o\);

-- Location: IOIBUF_X0_Y10_N1
\B~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B,
	o => \B~input_o\);

-- Location: IOIBUF_X0_Y21_N22
\A~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A,
	o => \A~input_o\);

-- Location: LCCOMB_X1_Y13_N16
\inst~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst~0_combout\ = (!\B~input_o\ & \A~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \B~input_o\,
	datad => \A~input_o\,
	combout => \inst~0_combout\);

-- Location: LCCOMB_X1_Y13_N10
inst5 : cycloneiii_lcell_comb
-- Equation(s):
-- \inst5~combout\ = (!\A~input_o\) # (!\B~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111111111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \B~input_o\,
	datad => \A~input_o\,
	combout => \inst5~combout\);

-- Location: LCCOMB_X1_Y13_N4
\inst3~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst3~0_combout\ = (\B~input_o\ & !\A~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \B~input_o\,
	datad => \A~input_o\,
	combout => \inst3~0_combout\);

ww_AGE <= \AGE~output_o\;

ww_AEB <= \AEB~output_o\;

ww_ALB <= \ALB~output_o\;
END structure;


