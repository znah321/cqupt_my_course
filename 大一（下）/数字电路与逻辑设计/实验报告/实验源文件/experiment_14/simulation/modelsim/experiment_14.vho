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

-- DATE "06/05/2020 14:17:47"

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

ENTITY 	lab1 IS
    PORT (
	seq : OUT std_logic_vector(6 DOWNTO 0);
	A : IN std_logic;
	C : IN std_logic;
	D : IN std_logic;
	B : IN std_logic;
	RBIN : IN std_logic;
	BIN : IN std_logic;
	LTN : IN std_logic
	);
END lab1;

-- Design Ports Information
-- seq[6]	=>  Location: PIN_203,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- seq[5]	=>  Location: PIN_41,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- seq[4]	=>  Location: PIN_161,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- seq[3]	=>  Location: PIN_64,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- seq[2]	=>  Location: PIN_120,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- seq[1]	=>  Location: PIN_98,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- seq[0]	=>  Location: PIN_145,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- LTN	=>  Location: PIN_151,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D	=>  Location: PIN_152,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- C	=>  Location: PIN_103,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B	=>  Location: PIN_82,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A	=>  Location: PIN_128,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- BIN	=>  Location: PIN_73,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- RBIN	=>  Location: PIN_100,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF lab1 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_seq : std_logic_vector(6 DOWNTO 0);
SIGNAL ww_A : std_logic;
SIGNAL ww_C : std_logic;
SIGNAL ww_D : std_logic;
SIGNAL ww_B : std_logic;
SIGNAL ww_RBIN : std_logic;
SIGNAL ww_BIN : std_logic;
SIGNAL ww_LTN : std_logic;
SIGNAL \seq[6]~output_o\ : std_logic;
SIGNAL \seq[5]~output_o\ : std_logic;
SIGNAL \seq[4]~output_o\ : std_logic;
SIGNAL \seq[3]~output_o\ : std_logic;
SIGNAL \seq[2]~output_o\ : std_logic;
SIGNAL \seq[1]~output_o\ : std_logic;
SIGNAL \seq[0]~output_o\ : std_logic;
SIGNAL \B~input_o\ : std_logic;
SIGNAL \A~input_o\ : std_logic;
SIGNAL \C~input_o\ : std_logic;
SIGNAL \D~input_o\ : std_logic;
SIGNAL \inst|72~4_combout\ : std_logic;
SIGNAL \BIN~input_o\ : std_logic;
SIGNAL \LTN~input_o\ : std_logic;
SIGNAL \inst|72~combout\ : std_logic;
SIGNAL \RBIN~input_o\ : std_logic;
SIGNAL \inst|66~9_combout\ : std_logic;
SIGNAL \inst|66~10_combout\ : std_logic;
SIGNAL \inst|66~8_combout\ : std_logic;
SIGNAL \inst|71~3_combout\ : std_logic;
SIGNAL \inst|71~combout\ : std_logic;
SIGNAL \inst|67~9_combout\ : std_logic;
SIGNAL \inst|67~10_combout\ : std_logic;
SIGNAL \inst|67~8_combout\ : std_logic;
SIGNAL \inst|70~4_combout\ : std_logic;
SIGNAL \inst|70~3_combout\ : std_logic;
SIGNAL \inst|70~combout\ : std_logic;
SIGNAL \inst|68~9_combout\ : std_logic;
SIGNAL \inst|68~10_combout\ : std_logic;
SIGNAL \inst|68~8_combout\ : std_logic;
SIGNAL \inst|69~8_combout\ : std_logic;
SIGNAL \inst|69~9_combout\ : std_logic;
SIGNAL \inst|69~combout\ : std_logic;
SIGNAL \inst|ALT_INV_67~8_combout\ : std_logic;
SIGNAL \inst|ALT_INV_71~combout\ : std_logic;
SIGNAL \inst|ALT_INV_72~combout\ : std_logic;
SIGNAL \inst|ALT_INV_69~combout\ : std_logic;
SIGNAL \inst|ALT_INV_68~8_combout\ : std_logic;
SIGNAL \inst|ALT_INV_70~combout\ : std_logic;
SIGNAL \inst|ALT_INV_66~8_combout\ : std_logic;

BEGIN

seq <= ww_seq;
ww_A <= A;
ww_C <= C;
ww_D <= D;
ww_B <= B;
ww_RBIN <= RBIN;
ww_BIN <= BIN;
ww_LTN <= LTN;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\inst|ALT_INV_67~8_combout\ <= NOT \inst|67~8_combout\;
\inst|ALT_INV_71~combout\ <= NOT \inst|71~combout\;
\inst|ALT_INV_72~combout\ <= NOT \inst|72~combout\;
\inst|ALT_INV_69~combout\ <= NOT \inst|69~combout\;
\inst|ALT_INV_68~8_combout\ <= NOT \inst|68~8_combout\;
\inst|ALT_INV_70~combout\ <= NOT \inst|70~combout\;
\inst|ALT_INV_66~8_combout\ <= NOT \inst|66~8_combout\;

-- Location: IOOBUF_X23_Y29_N9
\seq[6]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|ALT_INV_72~combout\,
	devoe => ww_devoe,
	o => \seq[6]~output_o\);

-- Location: IOOBUF_X0_Y10_N2
\seq[5]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|ALT_INV_66~8_combout\,
	devoe => ww_devoe,
	o => \seq[5]~output_o\);

-- Location: IOOBUF_X41_Y18_N2
\seq[4]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|ALT_INV_71~combout\,
	devoe => ww_devoe,
	o => \seq[4]~output_o\);

-- Location: IOOBUF_X5_Y0_N30
\seq[3]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|ALT_INV_67~8_combout\,
	devoe => ww_devoe,
	o => \seq[3]~output_o\);

-- Location: IOOBUF_X39_Y0_N23
\seq[2]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|ALT_INV_70~combout\,
	devoe => ww_devoe,
	o => \seq[2]~output_o\);

-- Location: IOOBUF_X26_Y0_N30
\seq[1]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|ALT_INV_68~8_combout\,
	devoe => ww_devoe,
	o => \seq[1]~output_o\);

-- Location: IOOBUF_X41_Y13_N9
\seq[0]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|ALT_INV_69~combout\,
	devoe => ww_devoe,
	o => \seq[0]~output_o\);

-- Location: IOIBUF_X16_Y0_N22
\B~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B,
	o => \B~input_o\);

-- Location: IOIBUF_X41_Y3_N15
\A~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A,
	o => \A~input_o\);

-- Location: IOIBUF_X28_Y0_N29
\C~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_C,
	o => \C~input_o\);

-- Location: IOIBUF_X41_Y15_N1
\D~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_D,
	o => \D~input_o\);

-- Location: LCCOMB_X29_Y4_N10
\inst|72~4\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|72~4_combout\ = (\B~input_o\ & (\A~input_o\ & (\C~input_o\))) # (!\B~input_o\ & (((!\C~input_o\ & !\D~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000000010000101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B~input_o\,
	datab => \A~input_o\,
	datac => \C~input_o\,
	datad => \D~input_o\,
	combout => \inst|72~4_combout\);

-- Location: IOIBUF_X7_Y0_N8
\BIN~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_BIN,
	o => \BIN~input_o\);

-- Location: IOIBUF_X41_Y15_N8
\LTN~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_LTN,
	o => \LTN~input_o\);

-- Location: LCCOMB_X31_Y4_N18
\inst|72\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|72~combout\ = ((\inst|72~4_combout\ & \LTN~input_o\)) # (!\BIN~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|72~4_combout\,
	datac => \BIN~input_o\,
	datad => \LTN~input_o\,
	combout => \inst|72~combout\);

-- Location: IOIBUF_X26_Y0_N15
\RBIN~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_RBIN,
	o => \RBIN~input_o\);

-- Location: LCCOMB_X29_Y4_N12
\inst|66~9\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|66~9_combout\ = (\C~input_o\ & (((\A~input_o\)))) # (!\C~input_o\ & (!\D~input_o\ & ((\A~input_o\) # (!\RBIN~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000011110001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \C~input_o\,
	datab => \RBIN~input_o\,
	datac => \A~input_o\,
	datad => \D~input_o\,
	combout => \inst|66~9_combout\);

-- Location: LCCOMB_X29_Y4_N6
\inst|66~10\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|66~10_combout\ = (\B~input_o\ & ((\inst|66~9_combout\) # (!\C~input_o\))) # (!\B~input_o\ & (!\C~input_o\ & \inst|66~9_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111100001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B~input_o\,
	datac => \C~input_o\,
	datad => \inst|66~9_combout\,
	combout => \inst|66~10_combout\);

-- Location: LCCOMB_X29_Y4_N24
\inst|66~8\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|66~8_combout\ = ((\inst|66~10_combout\ & \LTN~input_o\)) # (!\BIN~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|66~10_combout\,
	datac => \BIN~input_o\,
	datad => \LTN~input_o\,
	combout => \inst|66~8_combout\);

-- Location: LCCOMB_X29_Y4_N22
\inst|71~3\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|71~3_combout\ = (!\B~input_o\ & ((\C~input_o\) # ((!\RBIN~input_o\ & !\D~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101000001010001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B~input_o\,
	datab => \RBIN~input_o\,
	datac => \C~input_o\,
	datad => \D~input_o\,
	combout => \inst|71~3_combout\);

-- Location: LCCOMB_X29_Y4_N28
\inst|71\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|71~combout\ = ((\LTN~input_o\ & ((\inst|71~3_combout\) # (\A~input_o\)))) # (!\BIN~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101100110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|71~3_combout\,
	datab => \BIN~input_o\,
	datac => \A~input_o\,
	datad => \LTN~input_o\,
	combout => \inst|71~combout\);

-- Location: LCCOMB_X29_Y4_N0
\inst|67~9\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|67~9_combout\ = (\C~input_o\ & (((!\A~input_o\)))) # (!\C~input_o\ & ((\A~input_o\) # ((!\RBIN~input_o\ & !\D~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \C~input_o\,
	datab => \RBIN~input_o\,
	datac => \A~input_o\,
	datad => \D~input_o\,
	combout => \inst|67~9_combout\);

-- Location: LCCOMB_X29_Y4_N2
\inst|67~10\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|67~10_combout\ = (\B~input_o\ & (\A~input_o\ & !\inst|67~9_combout\)) # (!\B~input_o\ & ((\inst|67~9_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010110100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B~input_o\,
	datac => \A~input_o\,
	datad => \inst|67~9_combout\,
	combout => \inst|67~10_combout\);

-- Location: LCCOMB_X31_Y4_N20
\inst|67~8\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|67~8_combout\ = ((\inst|67~10_combout\ & \LTN~input_o\)) # (!\BIN~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst|67~10_combout\,
	datac => \BIN~input_o\,
	datad => \LTN~input_o\,
	combout => \inst|67~8_combout\);

-- Location: LCCOMB_X29_Y4_N18
\inst|70~4\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|70~4_combout\ = (!\A~input_o\ & ((\B~input_o\) # ((!\RBIN~input_o\ & !\D~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101000001011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B~input_o\,
	datab => \RBIN~input_o\,
	datac => \A~input_o\,
	datad => \D~input_o\,
	combout => \inst|70~4_combout\);

-- Location: LCCOMB_X29_Y4_N4
\inst|70~3\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|70~3_combout\ = (\C~input_o\ & ((\D~input_o\))) # (!\C~input_o\ & (\inst|70~4_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110000001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst|70~4_combout\,
	datac => \C~input_o\,
	datad => \D~input_o\,
	combout => \inst|70~3_combout\);

-- Location: LCCOMB_X29_Y4_N30
\inst|70\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|70~combout\ = ((\inst|70~3_combout\ & \LTN~input_o\)) # (!\BIN~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst|70~3_combout\,
	datac => \BIN~input_o\,
	datad => \LTN~input_o\,
	combout => \inst|70~combout\);

-- Location: LCCOMB_X29_Y4_N20
\inst|68~9\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|68~9_combout\ = (\B~input_o\ & (((\C~input_o\) # (\D~input_o\)))) # (!\B~input_o\ & (!\RBIN~input_o\ & (!\C~input_o\ & !\D~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010100001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B~input_o\,
	datab => \RBIN~input_o\,
	datac => \C~input_o\,
	datad => \D~input_o\,
	combout => \inst|68~9_combout\);

-- Location: LCCOMB_X29_Y4_N14
\inst|68~10\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|68~10_combout\ = (\inst|68~9_combout\ & (((\D~input_o\) # (!\A~input_o\)))) # (!\inst|68~9_combout\ & (\C~input_o\ & (\A~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110110000101100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \C~input_o\,
	datab => \inst|68~9_combout\,
	datac => \A~input_o\,
	datad => \D~input_o\,
	combout => \inst|68~10_combout\);

-- Location: LCCOMB_X29_Y4_N8
\inst|68~8\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|68~8_combout\ = ((\inst|68~10_combout\ & \LTN~input_o\)) # (!\BIN~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst|68~10_combout\,
	datac => \BIN~input_o\,
	datad => \LTN~input_o\,
	combout => \inst|68~8_combout\);

-- Location: LCCOMB_X29_Y4_N16
\inst|69~8\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|69~8_combout\ = (\C~input_o\ & (((!\A~input_o\)))) # (!\C~input_o\ & (((\A~input_o\) # (\D~input_o\)) # (!\RBIN~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101111101011011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \C~input_o\,
	datab => \RBIN~input_o\,
	datac => \A~input_o\,
	datad => \D~input_o\,
	combout => \inst|69~8_combout\);

-- Location: LCCOMB_X29_Y4_N26
\inst|69~9\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|69~9_combout\ = (\inst|69~8_combout\ & ((\C~input_o\) # (\B~input_o\ $ (!\D~input_o\)))) # (!\inst|69~8_combout\ & (\B~input_o\ & (\C~input_o\ & \D~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110100011000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B~input_o\,
	datab => \inst|69~8_combout\,
	datac => \C~input_o\,
	datad => \D~input_o\,
	combout => \inst|69~9_combout\);

-- Location: LCCOMB_X31_Y4_N0
\inst|69\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|69~combout\ = ((\inst|69~9_combout\ & \LTN~input_o\)) # (!\BIN~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|69~9_combout\,
	datac => \BIN~input_o\,
	datad => \LTN~input_o\,
	combout => \inst|69~combout\);

ww_seq(6) <= \seq[6]~output_o\;

ww_seq(5) <= \seq[5]~output_o\;

ww_seq(4) <= \seq[4]~output_o\;

ww_seq(3) <= \seq[3]~output_o\;

ww_seq(2) <= \seq[2]~output_o\;

ww_seq(1) <= \seq[1]~output_o\;

ww_seq(0) <= \seq[0]~output_o\;
END structure;


