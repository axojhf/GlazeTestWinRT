// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "MainWindow.g.h"

#include "glaze/core/macros.hpp"
#include "glaze/json/json_ptr.hpp"
#include "glaze/json/ptr.hpp"
#include "glaze/json/read.hpp"
#include "glaze/json/write.hpp"
#include "glaze/json/prettify.hpp"
#include "glaze/util/progress_bar.hpp"
#include "glaze/api/impl.hpp"
#include "glaze/record/recorder.hpp"

namespace winrt::GlazeTestWinRT::implementation
{
	struct MainWindow : MainWindowT<MainWindow>
	{
		MainWindow();

		int32_t MyProperty();
		void MyProperty(int32_t value);

		void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
	};

	struct my_struct
	{
		int i = 287;
		double d = 3.14;
		std::string hello = "Hello World";
		std::array<uint64_t, 3> arr = { 1, 2, 3 };
	};

	template <>
	struct glz::meta<my_struct> {
		using T = my_struct;
		static constexpr auto value = object(
			"i", &T::i,
			"d", &T::d,
			"hello", &T::hello,
			"arr", &T::arr
		);
	};
}

namespace winrt::GlazeTestWinRT::factory_implementation
{
	struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
	{
	};
}
